#include<bits/stdc++.h>
using namespace std;
string q="";
int c[1000000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,s;
	cin>>a>>s;
	int d[a];
	for(int i=0;i<a;i++){
		cin>>d[i];
	}
    for(int i=0;i<a;i++){
    	q="";
    	for(int z=i;z<a;z++){
    		q+=d[z]+'0';
    		for(int x=a-1;x>z;x--){
    			if(d[x]==d[z]){
				    z+=x;
				    break;
			    }
			}
		}
        for(int z=0;z<q.length();z++){
        	c[q[z]-'0']++;
		}
	}
	c[d[a-1]]=a;
	for(int i=1;i<=s;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
