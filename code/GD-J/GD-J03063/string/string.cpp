#include<bits/stdc++.h>
using namespace std;
int a[200010],l[200010],r[200010],rr[200010];
char c[200010],lc[200010],rc[200010],rrc[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;n>=i;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long cnt=0,k=1;
	long long j=0;
	while(1){
		cnt+=a[k];
		if(cnt>sum/2){
			long long y=cnt-sum/2;
			l[k]=(sum/2)-(cnt-a[k]);
			lc[k]=c[k];
			r[1]=y;
			rc[1]=c[k];
			j++;
			break;
		}
		if(cnt==sum/2){
			l[k]=a[k];
			lc[k]=c[k];
			break;
		}
		l[k]=a[k];
		lc[k]=c[k];
		//cnt+=a[k];
		k++;
	}
	long long ll=k;
	k=j+1;
	while(1){
		cnt+=a[k+ll-j];
		r[k]=a[k+ll-j];
		rc[k]=c[k+ll-j];
		if(cnt==sum){
			break;
		}
		k++;
	}
	for(int i=1;k>=i;i++){
		rr[i]=r[k-i+1];
		rrc[i]=rc[k-i+1];
	}
	long long lk=1,rk=1,ans=0;
	while(lk<=ll && rk<=k){
		if(rr[rk]>l[lk]){
			if(rrc[rk]!=lc[lk])ans+=l[lk];
			rr[rk]-=l[lk];
			lk++;
		}
		if(rr[rk]<l[lk]){
			if(rrc[rk]!=lc[lk])ans+=rr[rk];
			l[lk]-=rr[rk];
			rr[rk]=0;
			rk++;
		}
		if(rr[rk]==l[lk]){
			if(rrc[rk]!=lc[lk])ans+=rr[rk];
			l[lk]=0;
			rr[rk]=0;
			rk++;
			lk++;
		}
	}
	cout<<ans;
	return 0;
} 


