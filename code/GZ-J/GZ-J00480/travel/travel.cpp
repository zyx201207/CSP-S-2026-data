//GZ-J00480 赵浩钦 遵义航天高级中学 
#include<bits/stdc++.h>
using namespace std;
struct s{
	int n;
	int n1;
	char m;
}; 
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    s a[2];
    for(int i=1;i<=2;i++){
    	cin>>a[i].n>>a[i].n1>>a[i].m;
	}
	if(a[0].n!=a[1].n){
		cout<<"0000";
	}else{
		if(a[0].n1!=a[1].n1){
			cout<<"1000";
		}else{
			if(((a[0].m<='C'&&a[1].m<='C')||(a[0].m>'C'&&a[1].m>'C'))){
				cout<<"1100";
			}else{
				if(!((a[0].m+1==a[1].m)||(a[0].m-1==a[1].m))){
					cout<<"1111";
				}
				else if(!(a[0].m=='D'||a[0].m=='F'||a[1].m=='D'||a[1].m=='F')){
					cout<<"1111";
				}else cout<<"1110";
			}
		}
	}
    
//    fclose(stdin);
//    fclose(stdout);
	return 0;
}

