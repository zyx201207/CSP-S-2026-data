#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r"stdin);
	freopen("card.out","w"stdout);
    int  q,w,e,r;
    cin>>q>>w;
    for(int i=0;i<=1;i++){
    	cin>>i>>e>>i>>r;
    	if(i==1){
    		cout<<w<<" "<<i<<" "<<q<<endl;
		}
	}
	return 0;
} 
