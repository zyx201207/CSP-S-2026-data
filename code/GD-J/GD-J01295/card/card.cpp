#include<bits/stdc++.h>
using namespace std;
deque<int> st;
int a[500005],ans[500005],n,m;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			st.push_front(-1);
			bool b=0;
			while(st.back()!=-1){
				if(st.back()==a[j]){
					b=1;
				}
				if(b==0){
					st.push_front(st.back());
					st.pop_back();
				}
				if(b==1){
					st.pop_back();
				}
			}
			st.pop_back();
			st.push_front(a[j]);
		}
		while(!(st.empty())){
			ans[st.front()]++;
			st.pop_front();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
