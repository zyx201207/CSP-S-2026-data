#include<iostream>
using namespace std;
struct str{
	int a;
	char s;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	str Str[200000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>Str[i].a>>Str[i].s;
	}
	int i=0,j=n-1;
	long long z=0;
	while(i!=j){
		if(Str[i].s!=Str[j].s){
			z+=min(Str[i].a,Str[j].a);
			Str[i].a-=min(Str[i].a,Str[j].a);
			Str[j].a-=min(Str[i].a,Str[j].a);
			if(Str[i].a==0){
				i++;
			}else{
				j--;
			}
		}else{
			Str[i].a-=min(Str[i].a,Str[j].a);
			Str[j].a-=min(Str[i].a,Str[j].a);
			if(Str[i].a==0){
				i++;
			}else{
				j--;
			}	
		}
	}
	cout<<z<<endl;
	return 0;
}
