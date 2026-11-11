#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,cnt=4;
char e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&a,&c,&e,&b,&d,&f);
	if(e<f)swap(e,f);
	if(a==b){
		cout<<1;
		cnt--;
		if(c==d){
			cout<<1;
			cnt--;
			if(e<'D'||f>'C'){
				cout<<1;
				cnt--;
				if((int)e-f==1){
					cout<<1;
					cnt--;
				}
			}
		}
	}
	for(int i=0;i<cnt;i++)cout<<0;
	return 0;
}
