#include <bits/stdc++.h>
using namespace std;
int n,m;
int book[300005],a[500005],book1[300105],num=0;
vector <int> l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int s=1;s<=n;s++){
		for(int i=s;i<=n;i++){
			if(book1[a[s]]==0){
				l.push_back(a[s]);
				book1[a[s]]=1;
				num++;
			}	
			else{
				while(l[num-1]!=a[s]){
					book[l[num-1]]=0;
					l.pop_back();
					num--;
				}
			}
		}
		while(num!=0){
			book[l[num-1]]++;
			l.pop_back();
			num--;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<book[i]<<' ';
	return 0;
}
