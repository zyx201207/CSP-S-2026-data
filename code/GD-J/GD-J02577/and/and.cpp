#include<bits/stdc++.h>
using namespace std;
struct node{
	bool b[50],f;
}b[200100];
int n,m,a[200100],ha[40];
int ans;
void fun(int x){
	int s[50];
	
	int i=0,aa=a[x];
	while(aa!=0){
		s[i]=aa%2;
//		cout<<aa<<" "<<aa%2<<" "<<s[i]<<" "<<i<<endl;
		aa/=2;
		i++;
	}
	for(int j=1;j<=i;j++){
//		cout<<i-j<<" "<<s[j]<<endl;
		b[x].b[j]=s[j-1];
		if(s[j-1]==1)  ha[j]++;
	}
//	for(int j=1;j<=30;j++) cout<<b[x].b[j]<<" ";
//	cout<<endl;
}
int mi(int x){
	int r=1;
	for(int i=1;i<x;i++){
		r*=2;
	}
	return r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		fun(i);
	}
//	for(int i=1;i<=30;i++) cout<<ha[i]<<" ";
//	cout<<endl;
	for(int i=30;i>=1;i--){
		if(ha[i]>=m){
//			cout<<i<<endl;
			for(int j=1;j<=n;j++){
				if(b[j].f) continue;
				if(!b[j].b[i]){
					b[j].f=true;
					for(int k=1;k<=30;k++){
						if(b[j].b[k]) ha[k]--;
					}
				}
			}
		}
	}
	for(int i=1;i<=30;i++){
		if(ha[i]>=m){
			ans+=mi(i);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}//10:50 
