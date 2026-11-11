#include<bits/stdc++.h> 
using namespace std;
long long ans,n,cnt,num;
string str;
char lter;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num>>lter;
		cnt+=num;
		for(int j=1;j<=num;j++){
			str+=lter;
		}
	} 
	for(int i=0;i<cnt/2;i++){
		if(str[i]!=str[cnt-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
