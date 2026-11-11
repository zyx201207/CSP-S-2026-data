#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,t=0;
	std::cin>>n>>m;
	int s[n+100]={};
	for(int i=0;i<n;i++) std::cin>>s[i];
	for(int i=0;i<m;i++){
		if(t!=0){
			std::cout<<' ';
		}
		t++;
		std::cout<<s[1+i]-s[3*i];
	}
	return 0;
}
