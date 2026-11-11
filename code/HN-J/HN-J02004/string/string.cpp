#include<bits/stdc++.h>
using namespace std;
int n,a[200005],f;
char b[200005];
long long c=0,sum=0;
void(long long c){
	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		c+=a[i];
	}
	int f=a[0];
	for(int i=0;i<n;i++){
		
		if(b[0]==b[i+1]){
			f=f+a[i];
			
			a[0]=a[0]+a[i+1];
			
		}
		else{
			break;
		}
	}
	while(f){
		if(b[c-f]!=b[0]){
			sum++;
		}
		f--;
	}
	if(a[0]>(c/2+1)){
		cout<<c-a[0];
		return 0;		
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
