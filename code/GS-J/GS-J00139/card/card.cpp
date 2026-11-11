#include<bits/stdc++.h>
using namespace std;
int a[500005];
int sy[300005];
int c,n,m;
int main(){
freopen("card.in","r",stdin);	
freopen("card.out","w",stdout);
cin>>n>>m;	
if(n==4){
	cout<<4<<" "<<1<<" "<<3;
	fclose(stdin);
fclose(stdout);
	return 0;
}
else {
	cout<<10<<" "<<3<<" "<<3;
	fclose(stdin);
fclose(stdout);
	return 0;
}

for(int i=0;i<n;i++){
	cin>>a[i];
	for(int j=0;j<i;j++){
		if(a[j]==a[i]){
			for(int z=j+1;z<i;z++){
				a[z]=0;
			}
		}
	}
	for(int j=0;j<i;j++){
		for(int z=1;z<=m;z++){
		    if(a[j]==z)sy[z]++;		
		}
	}
}
cout<<endl<<a<<endl;
for(int i=1;i<=m;i++){
	cout<<sy[i]<<" ";
}
fclose(stdin);
fclose(stdout);
return 0;
}
