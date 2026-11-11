#include <iostream>
int e;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for (int i = 2,i >= 1,i++){
		e[i] = e[i]+e[i+1];
		if (i<0){
			cout << "3";
		}
	}
	freclose("card.in",stdin);
	freclose("card.out",stdout);
	return 0;
}
