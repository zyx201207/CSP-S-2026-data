#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	while(str.size()!=0){
		str.pop_back();
		
	}
	ll n;
	cin>>n;
	
	ll cou=0;
	int same=1;;
	for(int i=0;i<n;i++){
		ll c;
		char a,la;
		cin>>c>>a;
		int aa=a-'a';
		cou+=c;
		if(i!=0 && a!=la){
			same=0;
		}
		for(int i=0;i<c;i++){
			str.push_back(aa);
		}
		la=a;
	}
	cou;
	ll ans=0;
	if(n==1 || same==1){
		cout<<0;
	}else{
		for(int i=0;i<=cou/2;i++){
		    if(str[i]!=str[cou-i]){
			    ans++;
		    	
		    }else{
		    	//cout<<str[i]<<str[cou-i];
		    	
		    }
	    }
	    cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
