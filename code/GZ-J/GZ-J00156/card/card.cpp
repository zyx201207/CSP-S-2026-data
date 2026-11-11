//GZ-J00156 遵义市播州区实验学校 余晟睿
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,y,e,s;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==2)  {
			e=i;
			break;
		}
	
	}
	cout<<n-1<<e<<m;
	fclose(stdin);
	fclose(stdout);
}
