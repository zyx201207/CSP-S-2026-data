#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	long long sum=0,ans=0;
	bool f=true,f2=true;
	string s1;
	long long tot=1;
	cin>>a[1]>>c[1];
	for(int i=1;i<=a[1];i++) s1[tot++]=c[1];
	sum+=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		if(a[i]!=a[i-1]) f=false;
		if(c[i]!=c[i-1]) f2=false;
		for(int j=1;j<=a[i];j++) s1[tot++]=c[i];
	}
	if(f2==true){
		cout<<0;
		return 0;
	}
	else if(f==true){
		for(int i=1;i<=n/2;i++){
			if(c[i]!=c[n-i+1]) ans+=a[i];
		}
		cout<<ans;
	}
	else{
		//for(int i=1;i<=tot;i++) cout<<s1[i];
		//cout<<endl;
		for(int i=1;i<=sum/2;i++){
			//cout<<sum<<endl;
			//cout<<s1[i]<<" "<<s1[sum-i+1]<<endl;
			if(s1[i]!=s1[sum-i+1]){
				++ans;
				//cout<<ans<<" ";
			}
		}
		//cout<<endl;
		cout<<ans;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
