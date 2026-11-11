//GZ-J00297 Ёбндлн 
#include <bits/stdc++.h>
using namespace std;

int a[500004];

struct list1{
	int num,place;
	bool st;
};
list1 b[30004];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=n;i>=1;i--){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(!b[a[i]].st){
			b[a[i]].st=true;
			b[a[i]].place=i;
		}else{
			//cout<<b[a[i]].place;
			for(int j=b[a[i]].place+1;j<i;j++){
				//cout<<j;
				if(b[a[j]].place<i && b[a[j]].place>b[a[i]].place){
					b[a[j]].st=false;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j].st){
				b[j].num++;
				//cout<<j<<' '<<i<<endl;
			} 
		}
	}for(int i=1;i<=m;i++){
		cout<<b[i].num<<' ';
	}
	fclose(stdin);
	fclose(stdout);
}

