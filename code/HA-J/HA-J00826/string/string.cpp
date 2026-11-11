#include<bits/stdc++.h>
using namespace std;
string a = "";
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int t;
    cin>>t;
	long long sum = 0;
    while(t--){
    	long long s;
    	char f;
    	cin>>s>>f;
    	string a2 = "";
    	a2+=f;
    	while(a2.size()*2<=s){
    		a2+=a2;
    	}
    	for(long long i = a2.size();i<s;i++){
    		a2+=f;
    		
    	}
    	a+=a2;
    }
	for(int i = 0;i<=(a.size()-1)/2;i++){
    	if(a[i]!=a[a.size()-1-i]){
    			sum++;
    	}
    }
    cout<<sum<<endl;
	return 0;
}
