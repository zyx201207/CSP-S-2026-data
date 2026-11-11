#include<bits/stdc++.h>
using namespace std;
int n,m;int cntt=0;
int lll[500005],lll2[300005],lll3[300005],lll4[300005];
stack<int>q;
//freopen
//我freopen没打错吧 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
	    cin>>lll[i];
	}
	for(int j=1;j<=n;j++){
		
	    for(int i=j;i<=n;i++){
		    if(lll2[lll[i]]!=0){
			    while(q.top()!=lll[i]){
				    lll2[q.top()]--;
				    q.pop();
			    }
		    }
		    else{
			    q.push(lll[i]);
			    lll2[lll[i]]++;
		    }
	    }
	    while(!q.empty()){
	    	
	    	lll2[q.top()]--;lll4[q.top()]++;
	    	q.pop();
		}
	    for(int i=1;i<=m;i++){
	    	if(lll4[i]!=0)
	    	    lll3[i]++;
	    	lll4[i]=0;
		}
    }
    for(int i=1;i<=m;i++){
    	
	   	cout<<lll3[i]<<' ';
	   	
	}
	return 0;
}//怎么感觉这题比第二和三题简单awA 
/*

初二200多分够拿奖吗？
感觉去S组就是被炸鱼的
现在是 2026/10/31 10:28
两个星期没写代码都没手感了

做完了可以玩游戏吗（我要上迷惑大赏！！！） 
*/












//11：40          好饿啊
