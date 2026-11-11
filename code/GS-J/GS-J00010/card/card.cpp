 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
 	//freopen("string.in","r",stdin);
 	//freopen("string.out","w",stdout);
 	int n,js=0;
 	cin>>n;
 	char c1[n/2+5];//前半栈文字 
 	int a1[n/2+5];//前半栈数字 
 	char c2[n/2+5];//后半栈文字 
 	int a2[n/2+5];//后半栈数字 
 	for(int i=1;i<=n/2;i++)
 	{
 		int b;
 		cin>>b;
 		a1[i]=b;//前半数字进栈 
 		cin>>c1[i];//前半文字进栈 
	}
	for(int i=n;i>n/2;i--)//后半倒序进栈
	{
		int b;
 		cin>>b;
 		a1[i]=b;//后半数字进栈 
 		cin>>c1[i];//后半文字进栈 
	} 
	//完成进栈
	for(int i=0;i<n;i++)//开始顶部相减 
	{
		//先比较
		if(a1[]>a2[i]) 
	 } 
 	return 0;
 }
