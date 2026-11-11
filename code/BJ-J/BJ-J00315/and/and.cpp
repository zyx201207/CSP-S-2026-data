#include<bits/stdc++.h>
using namespace std;
#define int long long
string s[200005];
string kkk(int k){
	string str="";
	while(k!=0){
		if(k%2==0){
			str+='0';
			k/=2;
		}
		else{
			str+='1';
			k/=2;
		}
	}
	return str;
}
string huo(string s1,string s2){
	string s3=""; 
	for(int i=0;i<min(s1.size(),s2.size());i++){
		if(s1[i]=='1' && s2[i]=='1'){
			s3[i]='1';
		}
		else{
			s3[i]='0';
		}
	}
	return s3;
}
int zhuan(string str){
	int ans=0;
	int k=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			ans+=k;
		}
		k*=2;
	}
	return ans;
}
int ans666=0;
void dfs(int x,int y,string sss){
	if(x==0 && y==0){
		ans666=max(ans666,zhuan(sss);
		return ;
	}
	if(x==0 || y==0){
		return ;
	}
	dfs(x-1,y,sss);
	if(sss==""){
		sss=s[x];
	}
	dfs(x-1,y-1,huo(sss,s[x]));
}
void todoelse(int n,int m){
	dfs(n,m,"");
	cout<<ans666;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1){
    	int maxx=0;
    	for(int i=1;i<=n;i++){
    		int k;
    		cin>>k;
    		maxx=max(maxx,k);
    	}
    	cout<<maxx;
    	return 0;
    }
    if(m==n){
    	 for(int i=1;i<=n;i++){
    		int k;
    		cin>>k;
    		s[i]=kkk(k);
   	 }
   	 string sss=s[1];
   	 for(int i=2;i<=n;i++){
   	 	sss=huo(sss,s[i]);
   	 }
   	 cout<<zhuan(sss);
	return 0;
    }
    for(int i=1;i<=n;i++){
    	int k;
    	cin>>k;
   	s[i]=kkk(k);
    }
    todoelse(n,m);
    return 0;
}