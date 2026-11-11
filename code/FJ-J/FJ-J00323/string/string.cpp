#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans;
struct{
	int a;
	char b;
}s[10000];
bool z[10000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].b;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[i].b==s[j].b){
				cnt++;
			}
		}
	}cout<<0;
	return 0;
}
