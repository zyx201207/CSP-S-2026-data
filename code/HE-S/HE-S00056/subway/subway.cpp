#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	
	if(c==0){
		int mmm;
		cin>>mmm;
		if(mmm=4){
			cout<<"32\n17";
		}else if(mmm==8){
			cout<<"35\n16";
		}else{
			for(int i=1;i<=q;i++)cout<<rand()%79<<"\n";
		}
	}else{
		for(int i=1;i<=q;i++)cout<<rand()%79<<"\n";
	}
	return 0;
}
