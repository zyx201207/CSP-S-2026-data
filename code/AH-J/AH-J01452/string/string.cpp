#include<bits/stdc++.h>
using namespace std;

int n,z[100000050];

string s[10000005];
string m[10000005];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
int q=0,l=0;
for(int i=0;i<n;i++){
	cin>>z[i];
	cin>>s[i];
	for(int w=0;w<z[i];w++){
	m[q]=s[i];
	q++;
	}}
int y=q;
for(int i=0;i*1<q;i++){
	if(m[i]!=m[y]){
		m[y]=m[i];
		l++;
		}
	y--;
	}
cout<<l;

return 0;
}

