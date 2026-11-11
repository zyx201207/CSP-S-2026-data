#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],a1[200001],tot1,sum,cnt,a2[200001],tot2,cnt1,cnt2,ans;
char b[200001]={'A'},b1[200001],b2[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(b[i]==b[i-1])a1[tot1]+=a[i];
		else{
			a1[++tot1]=a[i];
			b1[tot1]=b[i];
		}
		sum+=a[i];
	}
	for(int i=1;i<=tot1;i++){
		if(cnt+a1[i]>sum/2){
			for(int j=tot1;j>i;j--){
				a2[++tot2]=a1[j];
				b2[tot2]=b1[j];
			}
			tot1=i;
			tot2++;
			long long cntjiaa1i=cnt+a1[i];
			a1[i]=sum/2-cnt;
			if(sum/2-cnt==0)tot1--;
			a2[tot2]=cntjiaa1i-sum/2;
			b2[tot2]=b1[i];
			if(sum%2)a2[tot2]--;
			break;
		}
		cnt+=a1[i];
	}
	a1[tot1+1]=sum/2+1;
	a2[tot2+1]=sum/2+1;
	for(int i=1;i<=tot1;i++)a1[i]+=a1[i-1];
	for(int i=1;i<=tot2;i++)a2[i]+=a2[i-1];
	for(int i=tot1;i>=1;i--){
		a1[i]=a1[i-1]+1;
		//cout<<a1[i]<<" "<<b1[i]<<"   ";
	}//cout<<"\n";
	for(int i=tot2;i>=1;i--){
		a2[i]=a2[i-1]+1;
		//cout<<a2[i]<<" "<<b2[i]<<"   ";
	}//cout<<"\n";
	for(int i=1;i<=tot1;i++){
		cnt1=a1[i];
		while(cnt1<a1[i+1]){
			int x=upper_bound(a2+1,a2+tot2+1,cnt1)-a2-1;
			if(a2[x+1]>=a1[i+1]){
				if(b1[i]!=b2[x])ans+=a1[i+1]-cnt1;
				break;
			}else{
				if(b1[i]!=b2[x])ans+=a2[x+1]-cnt1;
				cnt1=a2[x+1];
			}
		}
	}
	cout<<ans;
	return 0;
}
