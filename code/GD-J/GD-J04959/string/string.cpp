#include<bits/stdc++.h>
using namespace std;
int main(){
	freogen("string","r",stdin);
	freogen("string","w",stdout);
	int n,a,cnt=0,b=0;
	string c,s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
		cnt+=a;
	}
	for(int i=0;i<cnt;i++){
		if(s[i]==s[cnt-i-1]){
			break;
		}else{
			s[cnt-i-1]=s[i];
			b+=1;
		}
	}
	cout<<b;
	return 0;
}
