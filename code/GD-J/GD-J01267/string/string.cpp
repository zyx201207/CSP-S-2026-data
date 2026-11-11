#include<bits/stdc++.h>
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,t1[int(2*pow(10,5))],tot=0,cs=0;
	char t2[int(2*pow(10,5))];
	char st[int(1e6+7)];
	std::cin>>n;
	for(int i=0;i<n;i++){
		std::cin>>t1[i]>>t2[i];
	}
	for(int i=0;i<n;i++){
		for(int j=cs;j<cs+t1[i];j++){
			st[j]=t2[i];
		} 
		cs+=t1[i];
	} 
	for(int i=0;2*i<cs;i++){
		if(st[i]!=st[cs-i-1]){
			tot++;
		}
		//std::cout<<st[i];
	}
	std::cout<<tot;
}
