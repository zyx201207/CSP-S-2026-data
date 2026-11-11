#include<bits/stdc++.h>
using namespace std;
struct hw{
	int x;
	string b;
}a[200005];
int n,sum=0;
string s;
int m=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].b;
		for(int j=m;j<m+a[i].x;j++) s+=a[i].b;
		m+=a[i].x;
    }
	
	for(int i=0;i<m;i++){
		if(s[i]!=s[m-1-i]) sum++;
	}
	cout<<sum/2;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
