#include <bits/stdc++.h>
using namespace std;
long long num;
string t,e;
int main(){
	freopen ("string.in","w",stdin);
	freopen ("string.out","r",stdout);
	int n;
	cin>>n;
	long int a[n+10];
	char c[n+10];
	for (int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for (;a[i]>0;a[i]--) {
			t=t+c[i];
			e=c[i]+e;
		}
		
	}
	
	while (t!=e){
		for (int i=0;i<t.size();i++){
			int j=t.size();
			if (t[i]!=e[j]){
			/*	if (t[i]==t[i+1]){
					e[j]=t[i];
				}else if (e[j]==e[j-1]){
					t[i]=e[j];
				}*/
				e[j]=t[i];
				num++;
			}
			j--;
		}
	}
	cout <<num;
	return 0;
}
