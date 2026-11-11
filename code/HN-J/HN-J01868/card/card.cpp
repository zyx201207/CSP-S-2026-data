#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],s=0,b=0;
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		s=0;
		for(int j=0;j<n;j++){
			b++;
			if(a[i]==a[i-1]){
				b-=i;
				if(b==i) s++;
			}
		}
		cout<<s<<' ';
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}			
