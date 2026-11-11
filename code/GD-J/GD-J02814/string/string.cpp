#include<bits/stdc++.h>
using namespace std;
int n,z=0;
long long a[1000000000];
char c[100000000]; 
string s;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++)
		s+=c[i];
	}
	int x=s.size()-1;
	for(int i=0;i<=(s.size())/2;i++){
		if(s[i]!=s[x]){
			z++;
		}
		x--;
    }
    cout<<z;
    fclose(stdin);
	fclose(stdout);
	return 0;
}
