//GZ-J00205 贵阳市第十八中学 钟承邑
#include<bits/stdc++.h>
using namespace std;
int n;
string str;
string stra,strb;
bool ishw(string str){
	if(stra==strb) return true;
	else return false;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int ai;
        string ci;
        cin>>ai>>ci;
        for(int j=1;j<=ai;j++){
            str+=ci;
        }
    }
	if(str.size()%2==0){
		stra=str.substr(0,str.size()/2);
		for(int i=str.size()-1;i>=str.size()/2;i--){
			strb+=str[i];
		}
	}
	else{
		stra=str.substr(0,str.size()/2);
		for(int i=str.size()-1;i>=str.size()/2+1;i--){
			strb+=str[i];
		}
	}
	if(ishw(str)){
    	cout<<0;
    	return 0;
	}
	int ans=0;
	for(int i=0;i<=str.size()/2-1;i++){
		char nowa=stra[i],nowb=strb[i];
		if(nowa!=nowb) ans++;
	}
	cout<<ans;
    return 0;
}
