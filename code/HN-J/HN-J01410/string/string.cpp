#include<bits/stdc++.h>
using namespace std;
char a[200005];
long int n,x[200005],tot;
char y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		cin>>a[i];
	}
	int s=1,e=n;
	for(int i=1;i<=n;i++){
		if(a[s]!=a[e]){
			if(x[s]>=x[e]){
				tot=tot+x[e];
				x[s]=x[s]-x[e];
				a[e]=a[s];
				x[e]=0;
				e--; 
			}
			else
			{
			tot=tot+x[s];
			x[e]=x[e]-x[s];
			a[s]=a[e];
			x[s]=0;
			s++;
		}
		}
		else{
			x[s]=0;
			x[e]=0;
		s++;
		e--;
	}
}
	cout<<tot;
	return 0;
}

