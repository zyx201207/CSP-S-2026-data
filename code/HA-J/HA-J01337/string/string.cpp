#include<bits/stdc++.h>
using namespace std;
int k;
bool st(string x){
	string y[x.size()];
	int j=0;
	for(long long i=x.size()-1;i>=0;i--){
		if(x[i]==x[j]){
			j+=0;
			j++;
			continue;
		}else{
			return false;
		}
		
	}
	return true;
}
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n];
	string s;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		string c;
		cin>>c;
		for(long long j=0;j<a[i];j++){
			s+=c;
		}
	}
	long long g=s.size()-1;
	for(long long i=0;i<=s.size()-1;i++){
		if(st(s)){
			cout<<k;
			break;
		}else{
		    s[g]=s[i];
		    k++;
		    g--;
	    }
	}
	return 0;
}
