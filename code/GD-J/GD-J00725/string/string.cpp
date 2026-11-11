#include<bits/stdc++.h>
using namespace std;
int g[200005];
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	int n;
	cin >>n;
	string s="";
	int ans=0;
	for(int i=0;i<n;i++){
		cin >>g[i];
		cin >>c[i];
		for(int j=0;j<g[i];j++){
			s+=c[i];
		}
	}
	if(n==1){
		cout <<0;
		return 0;
	}
	else if(n==2){
		if(c[0]==c[1]){
			cout <<0;
			return 0;
		}
		else{
			cout <<min(g[0],g[1]);
		    return 0;
	    }
	}
	else{
		int l=s.size();
		for(int i=0;i<l;i++){
			if(s[i]==s[l-i-1]){
				continue;
			}
			else{
				s[l-i-1]=s[i];
				ans++;
			}
		}
	}
	cout <<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
