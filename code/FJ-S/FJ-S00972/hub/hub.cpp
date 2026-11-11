#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) 
	{
		cin>>n>>k;
		if(k>=(n-1)/2) cout<<"1\n";
		else if(k==1) cout<<n/4<<endl;
		else cout<<2<<endl;
	}
	return 0;
}
/*
额啊，感觉要AFO了，又感觉还有希望
因为T1卡了很久，但是17:54调出来了！！！yeah~ 
预估100+（32~48）+8+？=（140~156）+？，希望CCF少爷机能让我T2多卡16分过去，sto，我明年一定交更多钱:)
（觉得我T4这坨达芬能有分吗） 
可能是最后一年学 OI 了，也可能是最后一次打CCF系列赛了
寒假创新人才走不了就真的要AFO了 
感谢OI，感谢CCF（？），感谢XMYZ，感谢在看这一段代码的你
三年OI之路快结束了，但是前面的路还很长呢。 
rp++ 
----2026.10.31 18:28
*/ 
