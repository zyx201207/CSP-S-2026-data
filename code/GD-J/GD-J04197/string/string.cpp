#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <cstring>
using namespace std;
struct node{
	char ch;
	long long len;
};
long long r,n,sl,sr,ans,len[300005];
char ch[300005];
deque<node> st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n,r=n;
	for(int i=1;i<=n;i++)cin>>len[i]>>ch[i];
	for(int i=1;i<=r;i++){
		while(sr<sl+len[i]){
			st.push_back({ch[r],len[r]});
			sr+=len[r];
			r--;
		}
		int k=len[i];
		while(k){
			if(k<st.front().len){
				node nw=st.front();
				ans+=(st.front().ch!=ch[i])*k;
				nw.len-=k;
				k=0;
				st.pop_front();
				st.push_front(nw);
			}else{
				k-=st.front().len;
				ans+=(st.front().ch!=ch[i])*st.front().len;
				st.pop_front();
			}
		}
		sl+=len[i];
	}
	cout<<ans;
} 
