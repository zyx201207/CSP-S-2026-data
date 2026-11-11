#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int id1,id2;
	int c1,c2;
	char x1,x2;
	scanf("%d %d%c",&id1,&c1,&x1);
	scanf("%d %d%c",&id2,&c2,&x2);
	printf("%d",id1 == id2);
	printf("%d",id1 == id2 && c1 == c2);
	printf("%d",id1 == id2 && c1 == c2 && (x1 <= 'C' && x2 <= 'C' || x1 > 'C' && x2 > 'C'));
	printf("%d",id1 == id2 && c1 == c2 && (x1 <= 'C' && x2 <= 'C' || x1 > 'C' && x2 > 'C') && (abs(x1 - x2) == 1 || min(x1,x2) == 'D' && max(x1,x2) == 'F'));
	return 0;
}