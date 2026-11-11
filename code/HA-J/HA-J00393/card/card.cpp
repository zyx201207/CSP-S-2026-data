#include<bits/stdc++.h>
using namespace std;
struct ds{
	int y;
}ma[100005];
int a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,o;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int j=0;
	o=n;
	while(o--){
		int w=0;
		string b;
		b[w]=a[j];
		for(int i=j+1;i<n;i++){
			if(a[i]==b[b.find(a[i])]){
				w=b.find(a[i]);
			}else{
				w++;
				b[w]=a[i];
			}
		}
		for(int i=0;i<=w;i++){
			ma[b[i]-1].y+=1;
		}
		j++;
	}
	for(int i=0;i<m;i++){
		cout<<ma[i].y<<" ";
	}
	return 0;
}
