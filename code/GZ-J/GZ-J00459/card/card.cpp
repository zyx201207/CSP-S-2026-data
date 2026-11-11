//GZ-J00459 凤冈县第四中学 李朋秦
#include<bits/stdc++.h>
using namespace std;
int t[100001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<int>a2;
	int n,m,a1[100001];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a1[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
		if(a2.size()==0){
			a2.push(a1[j]);	
		}else{
			for(int x=0;x<a2.size();x++){
				if(a2[x]==a[j]){
					for(int y=0;y<a2.size();y++)a2.pop(a2[y]);
					a2.push(a[j]);
					break;
				}
			}
			
		}
	}
	
	for(int z=0;z<a2.size();z++){
		t[a2[z]]++;
		a2.push(a2[z]);
	}
}int c=0;
    while(t[c]!=0){
    	cout<<t[c]<<" ";
    	c++;
	}
	return 0;
} 
