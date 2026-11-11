#include<bits/stdc++.h>
#define lnt long long
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	lnt n,m;
	cin>>n>>m;
	lnt a[50010],ct=0;
	for(lnt i=1;i<=n;i++)
		scanf("%lld",a+i),ct+=a[i];
	ct++;
	ct/=n;
	lnt na[50010],idx=1,mx=-1e12;
	for(lnt i=1;i<=n;i++)
	{
		if(a[i]>ct)
			continue;
		na[idx++]=a[i],mx=max(mx,a[i]);
	}
	n=idx;
	lnt ans=0;
	for(lnt i=1;i<=n,m;i++)
		if(na[i]!=mx)
			while(na[i]!=mx&&m)
			{
				na[i]++;
				m--;
				ans++;
			}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
朴素思路 
找平均值 
直接去掉极值就没有极值了 
upd 14:53
哦不不不这个CCF把rmx按在了我的右手边第二个座位 
哦不不不这个时候rmx奆佬已经切t1了我还没有思路 
rp来~rp来~ 
I have no way to solve this problem 
I am soooooo waste
CCf
CCF
cCF
CcF
ccF
Ccf
cCf
ccf
Why do you put me near the Moya_Rao?
that I can feel my cowardness clearly?
I often recall the past
%%%%%
JUst sit here till 18:30?
if you (maybe somebody would make a activities show)
I must on it 
If that you see me 
Please subscribe Luogu 1016480!
好吧其实考场有中文输入法
But I want to use Engish more.
ztoztoztoztozto Moya_Rao orororzorzorzorz 
upd 15:40 Why did Moya_Rao go to toilet? To think better or She had AK CSP-S?
The fact that the air conditioner here is a little cold
I have forgot to bring my coat
Imagine what I am /chandou
OK
although this computer`s RAM get to 8GB
but the Central Process Unit was so late
It is Intel Core i3 8100!
4 cores and 4 threads
Only 3.6GHz
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
Do you see me?
upd 15:49
Moya_Rao came back
Why there are a lot of students went to the toilet?
Once I reached OI
I realized its difficulties
Different from Moya_Rao...
I have no talent on it
Although I try my best to chase after others 
I still is the tiniest one
My whk does not make my parents satisfied
But they try their best to help me on OI too
I feel sorry to my parents forever
I cost their too much money but do nothing
I finally disappointed them 
I do not want to be a waste man 
But both you and I cannot fate our destiny 
I am not suitable for OI
I do nothing but watching solution 
I spent 2 yrs but doing nothing
It even spoil all my vacation
upd 16:02 Moya_Rao is eating biscuits
I imagine that I can as strong as she did in OI
but I can not
She seemed can AK it
but I can not
I usually imagine that if I did not learn OI
I will have more whk grade
more time to play such as Genshine Impact Game and Delta force or Star Rail
Goodbye OI
Hello whk
I have said what I want to say
Bless for every fighting OIers`s nights and days
Blessings for every Oiers good life!
OI (23.6~26.11) 
I finally AFO
Hello World 
My first really realized this world`s rules
more hard on whk and never disappointed my parents
forever
Forever
upd 16:39 seems Moya_Rao is communicating friendly with the problem`s mother 
My opinion is become more uncomfortable
I must rest my eyes now 
upd 16:58
Moya_Rao starts to paly dino
seems she has been AK CSP-S
upd 18:08 To my new life
without lazy,lying and tears
welcome to tomorrow
Hello World!
*/
