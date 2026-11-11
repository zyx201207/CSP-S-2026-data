#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200005];
char s[200005];
char s1[200000005];
char s2[200000005];
int sum2;
int sum1;
char sss[200005];
int b[200005];
int c[200005];
int d[200005];
int e[200005],f[2000005];
int sum;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		cin>>s[i];
	}
	if(sum<=1e8){
		int s11=sum/2;
		int ss=0,l=1,ss1=0;
		for(int i=1;i<=n;i++){
			if(ss<s11){
				ss+=a[i];
				l=i;
			}
			else {
				ss1=ss-s11;
				break;	
			}
		}
		int num=0;
		int ans=0;
		for(int i=1;i<=l;i++){
			if(i!=l){
				for(int j=0;j<a[i];j++){
					s1[num]=s[i];
					num++;
				}
			}
			else{
				for(int j=0;j<(a[i]-ss1);j++){
					s1[num]=s[i];
					num++;
				}
			}
		}
		int num1=0;
		//cout<<endl;
		//cout<<ss1<<endl;
		for(int i=n;i>=n-l;i--){
			for(int j=0;j<a[i];j++){
				s2[num1]=s[i];
				num1++;
			}
		}
		
		if(sum%2!=0){
			num1-=1;
		}
		if(ss1!=0){
			num1-=(a[l]-ss1);
		}
		for(int i=0;i<s11;i++){
			if(s1[i]!=s2[i]){
				ans++;
			}
		}
		cout<<ans<<endl;
		}
	else{
		int s11=sum/2;
		int ss=0,l=1,ss1=0;
		for(int i=1;i<=n;i++){
			if(ss<s11){
				ss+=a[i];
				l=i;
			}
			else {
				ss1=ss-s11;
				break;	
			}
		}
		int ll=n-l;
		//cout<<l<<" "<<ss1<<endl;
		for(int i=1;i<=l;i++){
			if(i!=l){
				b[i]=a[i];
				sss[i]=s[i];
			}
			else{
				b[i]=a[i]-ss1;
				sss[i]=s[i];
				//cout<<b[i]<<endl;
			}
		}
		//cout<<ll<<" "<<l<<endl;
		for(int i=l+1;i<=n;i++){
			c[i]=a[i];
			s1[i]=s[i];
		}
		for(int i=l+1;i<=n;i++){
			d[n-i+1]=c[i];
			s2[n-i+1]=s1[i];
		}
		if(ss1!=0){
			d[ll+1]=ss1;
			s2[ll+1]=s[ll];
			ll+=1;
		}
		if(sum%2!=0){
			if(d[ll]==1){
				ll-=1;
			}
			else{
				d[ll]-=1;
			}
		}
		int ans=0;
		for(int i=1;i<=l;i++){
			e[i]=b[i];
		}
		for(int i=1;i<=ll;i++){
			f[i]=d[i];
		}
		int i=1;
		int j=1;
		sum2=b[1];
		sum1=d[1];
		while(i<=l&&j<=ll){
			//cout<<i<<" "<<j<<" "<<ans<<endl;
			//cout<<sum2<<" "<<sum1<<endl;
			if(sss[i]!=s2[j]){
				ans+=min(b[i],d[j]);			
			}
			if(b[i]>d[j]){
				b[i]-=d[j];
			}
			else if(d[j]>b[i]){
				d[j]-=b[i];
			}
			else{
				d[j]-=b[i];
				b[i]-=d[j];
			}
			if(sum2<sum1){	
				i++;
				sum2+=e[i];
			}
			else if(sum2>sum1){
				j++;
				sum1+=f[j];
			}
			else if(sum2==sum1){
				i++;j++;
				sum2+=e[i];
				sum1+=f[j];
				//cout<<"yes"<<endl;
			}
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
