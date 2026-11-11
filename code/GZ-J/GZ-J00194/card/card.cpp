//GZ-J00194 遵义市第十九中学 向博熙 
#include <bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,s1=0,t,s2=0;
	int c;
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>c;
		a[i]=c;
	}
	for(int i=1;i<n;i++){
		t=a[1];
		if(t==a[i]){
			for(int j=1;j<i;j++){
				s1+=a[j];
			}
		}
	}
	cout<<s1<<" ";
	cout<<t<<" ";
	for(int i=t;i<n;i++){
		s2+=a[i];
	}
	cout<<s2;
	return 0;
}
