#include<bits/stdc++.h>
typedef long long ll;
const bool islocal=0;
std::ifstream fin("crystal.in");
std::ofstream fout("crystal.out");
ll a[500005],n,p1,p2=0,m,ans=1,sum;
int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	(islocal?std::cin:fin)>>n>>m;for(ll i=0;i<n;i++)(islocal?std::cin:fin)>>a[i];
	std::sort(a,a+n);
	while(p2<n-1){
		p2++,sum+=(p2-p1)*(a[p2]-a[p2-1]);if(sum>m)sum-=a[p2]-a[p1],p1++;
		ans=std::max(ans,p2-p1+1);
	}(islocal?std::cout:fout)<<ans;
}
/* 
+---+-------------------+
|10K|               ||  |
|   |             ==++==|
+---+         /-\   ||  |
|            |   |      |
|    ______  |   |      |
|\==_  |  |  |   |      |
| \ ================_   |
|  \    -            /  |
|__ \ _= =_         / _=|
|  =-=     =---__ _-==  |
|         +---+  =      |
+---------| ! |---------+
|         +---+         |
|      KM 俾斯麦号      |
|对一个总部造成8点伤害。|
|        -=|*|=-        |
+-----------------------+
来日再会 
*/ 
