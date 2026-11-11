#include<bits/stdc++.h>
using namespace std;
deque<int> a;//500000’≈,300000÷÷≈∆ 
deque<int> b;//±£¥Ê 
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int j;
		cin>>j;
		for(int l=0;l<a.size();l++){
			if(j==a[l]){
				for(int o=a.size();o>=l;o--){
					a.pop_front();
				}
			}
		}
		a.push_front(j);
		b.push_front(j);
	}
	for(int i=a.size();i>0;i++){
		cout<<a[i]<<" ";
	}
	fclose(stdin); 
	fclose(stdout); 
}
