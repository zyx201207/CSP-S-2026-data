#include <bits/stdc++.h>

using namespace std;

int n,a[20005],l=0,lm=0,y=0;
char c[20005],x[50005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			x[l+j]=c[i];
		}
		l+=a[i]; 
	}
	lm=(l+1)/2;
	if(l%2==0){
		int lm2=l/2;
		for(int i=0;i<=lm2;i++){
			if(x[i]!=x[l-i+1]){
				y++;
			}
		}
	}
	else{
		for(int i=1;i<lm;i++){
			if(x[i]!=x[l-i+1]){
				y++;
			}
		}
	}
	cout<<y;
	return 0;
}
