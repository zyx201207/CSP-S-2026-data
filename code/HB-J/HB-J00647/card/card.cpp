#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5,M=3e5+5;
int ans[M]={};
int c[N]={};
int book[M];
stack<int>v;

void clear(){
    while(!v.empty()){
		v.pop();
	}
    memset(book,0,sizeof(book));
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    for(int i=1;i<=n;i++){
        clear();
        for(int j=i;j<=n;j++){
			
			//for(int k=1;k<=n;k++){cout<<book[k]<<" ";}
			//cout<<endl;
			
            if(book[c[j]]==1){
                while(v.top()!=c[j]){
                    book[v.top()]=0;
                    v.pop();
                }
                continue;
            }
            v.push(c[j]);
            book[c[j]]=1;
        }
        while(!v.empty()){
			ans[v.top()]++;
			v.pop();
		}
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0; 
}
