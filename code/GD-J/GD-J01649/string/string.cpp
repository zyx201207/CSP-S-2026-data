#include<iostream>
using namespace std;
int n;
int mp[200005];
char c[200005];
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>mp[i]>>c[i];
	}
	int i=1,j=n;
	while(i<=j){
		if(c[i]==c[j]){
			if(mp[i]>mp[j]){
				mp[i]-=mp[j];
				j--;
			}else if(mp[i]<mp[j]){
				mp[j]-=mp[i];
				i++;
			}else{
				i++;
				j--;
			}			
		}else if(c[i]!=c[j]){
			if(mp[i]>mp[j]){
				mp[i]-=mp[j];
				cnt+=mp[j];
				j--;
			}else if(mp[i]<mp[j]){
				mp[j]-=mp[i];
				cnt+=mp[i];
				i++;
			}else{
				cnt+=mp[i];
				i++;
				j--;
			}
		}
	}
	cout<<cnt;
}
