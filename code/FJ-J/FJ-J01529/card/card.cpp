#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500005],sum;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=m;k++){
		sum=0;
		stack<int> st;
		for(int j=1;j<=n;j++){  //从j开始打 
			int b[m+1]={0};
			for(int i=j;i<=n;i++){
				if(b[a[i]]>0){
					while(1){
						if(st.top()==a[i]){
							b[a[i]]--;
							st.pop(); 
							break;
						}
						b[st.top()]--;
						st.pop();
					}
				}
				st.push(a[i]);
				b[a[i]]++;
			}
			if(b[k]>0) sum++;
		}
		cout<<sum<<" ";
	}
	return 0;
}
