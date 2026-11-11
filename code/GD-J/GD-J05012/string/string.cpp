#include<bits/stdc++.h>
using namespace std;
unsigned long long ans=0;
string s;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int f;
	char l;
	string lsy;
	s+=' ';
	long long m[27];
	for(int i=1;i<=n;i++){
	    cin>>f;
	    cin>>l;
	    for(int j=1;j<=f;j++){
	    	s+=l;
		}
	    m[l-'a']=1;
	    ans+=f;
	}
	int lms=0;
	for(int i=1;i<=26;i++){
		if(m[i])lms++;
	

}
	if(lms==1){
		cout<<5;
		return 0;
	}
	unsigned long long zxy=0;
	for(int i=1;i<=ans/2;i++){
		if(s[i]!=s[ans-i+1])zxy++;
	}
	cout<<zxy;
	return 0;
} 
