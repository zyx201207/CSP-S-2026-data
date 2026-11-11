#include<bits/stdc++.h>
using namespace std;
int n,ans,y,cnt;
int lan1,lan2;
char c;
bool tu=1;
bool ah[30];
string s;
struct ch{
	int x;
	char cha;
}ch[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>y>>c;
		ch[i].cha=c;
		ah[c-'a']=1;
		ch[i].x=y;
}
	for(int i=0;i<=26;i++){
		if(ah[i]==1){
			cnt++;
		}
	}
	if(cnt==1){
		cout<<"0";
		
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=ch[i].x;j++){
			s+=ch[i].cha;
		}
}
	 lan1=s.size()/2;
	 lan2=s.size();
    for(int i=0;i<lan1;i++){
    	if(s[i]==s[lan2-i-1]){
    		
		}
		else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
