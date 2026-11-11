//GZ-J00688 遵义市第十二中学 刘俊逸 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,max=1;
	cin>>n>>m;
	int b[n+1];
	string c;
	for(int i=0;i<n;i++){
		cin>>b[i];
		int s=b[i];
		while(s!=0){
			if(s%2==0){
				c[i]='0'+c[i];
			}
			else{
				c[i]='1'+c[i];
			}
			s=s/2;
		}
	}
	sort(c.begin(),c.out());
	for(int i=0;i<n;i++){
		cout<<
	}
	return 0;
}
