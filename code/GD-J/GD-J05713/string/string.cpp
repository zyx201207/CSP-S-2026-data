#include<bits/stdc++.h>
using namespace std;
long long n,q[30],a[200005],w[30],e[30],ans,cnt,sum;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		if(b[1]==b[2]){
			cout<<0;
		}
		else{
			cout<<min(a[1],a[2]);
		}
	}
	/*for(int i=1;i<=n;i++){
		q[(b[i]-'0')-48]+=a[i];
	}
	sort(q+1,q+27);
	for(int i=1;i<=n;i++){
		if(q[i]!=0){
		  sum++; 
		}
	} 
	long long x=1,y=1;
	for(int i=1;i<=sum;i++){
		if(i%2==1){
			w[x]=q[i];
			x++;
		}
		if(i%2==0){
			e[y]=q[i];
			y++;
		}
	}
	if(sum%2==0){
		cnt=sum/2;
	}
	else{
		cnt=sum/2+1;
	}
	for(int i=cnt;i<=sum;i++){
		w[i]=e[sum-cnt];
	}
	int i=1,j=sum;
	for(;;){
		if(w[i]>w[j]){
			w[i]-=w[j];
			ans+=w[j];
			j++;
		}
		if(w[i]==w[j]){
			ans+=w[j];
			i++;
			j++;
		}
		if(w[j]>w[i]){
			w[j]-=w[i];
			ans+=w[i];
			i++;
		}
		if(i>=j){
			cout<<ans;
			return 0;
		}
	}*/
	
	return 0;
} 
