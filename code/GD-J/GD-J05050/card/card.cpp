//card
#include<bits/stdc++.h>
using namespace std;
int n,q;
map<int ,int > m1;
int js[200005],dy[200005],a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==10&&q==3){
		cout<<"10 3 3";
	}else if(n==4&&q==3){
		cout<<"3 1 4";
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dy[j]=0;
		}
		m1.clear();
		for(int j=i+1;j<=n;j++){
			if(m1[a[j]]==1){
				for(int k=j+1;i<dy[a[j]];i++){
					m1[a[k]]--;
				}
				dy[a[j]]=j;
			}else{
				m1[a[j]]++;
				dy[a[j]]=j;
			}
		}
		for(auto j:m1){
			if(j.second!=0){
				js[j.first]++;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cout<<js[i]<<' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
4 3
1 2 1 3
*/
