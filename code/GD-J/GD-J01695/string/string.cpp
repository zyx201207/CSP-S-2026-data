#include<bits/stdc++.h>
using namespace std;
int k[200003];
char ch[200003];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&k[i],&ch[i]);
	}
	long long ans=0;
	for(int i=1;i<=n/2;i++){
		if(k[i]>=k[n-i+1]){
			int j=n-i+1;
			while(k[j]==0) j--;
			while(k[i]>0&&k[i]>=k[j]){
				if(ch[i]!=ch[j]){
					ans+=k[j];
					//cout<<i<<" "<<j<<" "<<ans<<endl;
				}
				k[i]-=k[j];
				j--;
			}
			if(k[i]<k[j]){
				if(ch[i]!=ch[j]){
					ans+=k[i];
					//cout<<i<<" "<<j<<" "<<ans<<endl;
				}
				k[j]-=k[i];
			}
		}
		else{
			int j=n-i+1;
			while(k[i]==0) i++;
			while(k[j]>0&&k[j]>=k[i]){
				if(ch[i]!=ch[j]){
					ans+=k[i];
					//cout<<i<<" "<<j<<" "<<ans<<endl;
				}
				k[j]-=k[i];
				i++;
			}
			if(k[j]<k[i]){
				if(ch[i]!=ch[j]){
					ans+=k[j];
					//cout<<i<<" "<<j<<" "<<ans<<endl;
				}
				k[i]-=k[j];
			}
		}
	}
	cout<<ans;
	return 0;
}
