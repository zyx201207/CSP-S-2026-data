#include <bits/stdc++.h>
using namespace std;
int main(){
	
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,m,total=0,flg=0;
	string s,str;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		cin>>s;
		total+=m;
		for(int j=1;j<=m;j++){
			str+=s;
		}
	}
	
	if(total%2==0){
		for(int i=0;i<total/2;i++){
			for(int j=total-1;j>=total/2;j--){
				if(str[i]!=str[j]){
					flg++;
				}
			}
		}
	}else{
		for(int i=0;i<(total-1)/2-1;i++){
			for(int j=total-1;j>=(total-1)/2+1;j--){
				if(str[i]!=str[j]){
					flg++;
				}
			}
		}
	}
	
	cout<<flg;
	return 0;
}
