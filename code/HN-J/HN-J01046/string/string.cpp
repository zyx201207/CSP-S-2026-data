#include <bits/stdc++.h>
using namespace std;
long long n;long l[200001][3];long long hh;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	int mark=n;
	for(int i=1;i<=n;i++){
		cin>>l[i][1];
		char temp;
		cin>>temp;
		l[i][2]=(int)temp-'a'+1;
	}
	for(int i=1;i<=n;i++){
		while(l[i][1]>0){
			if(l[i][2]==l[mark][2]){
				l[mark][1]--;
				l[i][1]--;
			}
			else{
				hh++;
				l[mark][1]--;
				l[i][1]--;
			}
			if(!(l[mark][1]>0)) mark--;
		}
	}
	cout<<hh;
	return 0;
} 
