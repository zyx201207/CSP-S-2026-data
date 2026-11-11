#include<iostream>//string
#include<deque>
using namespace std;
deque<int>d;
deque<int>b;//back  
int ma=-117,a,n,m,tong[200232];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		d.push_back(a);
	}
for(int i=1;i<=n;i++){
	for(int j=1;j<=m-i+1;j++){
		b.push_back(d.front());
		d.pop_front();
		if(!b.empty()&&b.front()==b.back()){
			while(b.size()<1){
				b.pop_back();
			}
		}
	} 
	while(!d.empty()){
		tong[d.back()]++;
		d.pop_back();
	}
}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;	
}
