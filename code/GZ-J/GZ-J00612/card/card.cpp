//GZ-J00612郭中磊遵义市第四初级中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100000]={0},s[100000]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x,cnt=0;
	x=a[1];
	for(int i=0;i<n;i++){
		a[i]=s[i];
		if(a[i+1]!=s[i]){
			a[i+1]=s[i+1];
		}
		else{
			s[i]=a[i+1];
		}
		if(x==s[i+1])
			cnt++;
		cout<<cnt;
	}
	//fclose(stdin);
	//fclose(stdout);
}

