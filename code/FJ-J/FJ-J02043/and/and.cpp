#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.in","r",stdin);
	long long n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	if(m==1)
		cout << a[n-1];
	else if(m==2)
	{
		int mx=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(mx<(a[i]&a[j]))
					mx=a[i]&a[j];
			}
		}
		cout << mx;
	}
	else
	{
		int mx=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int i1=j+1;i1<n;i1++)
				{
					for(int j1=i1+1;j1<n;j1++)
					{
						for(int i2=j1+1;i2<n;i2++)
						{
							for(int j2=i2+1;j2<n;j2++)
							{
								for(int i3=j2+1;i2<n;i3++)
								{
									for(int j3=i3+1;j3<n;j3++)
									{
										for(int i4=j3+1;i3<n;i4++)
										{
											for(int j4=i4+1;j4<n;j4++)
											{
												for(int i5=j4+1;i5<n;i5++)
												{
													for(int j5=i5+1;j5<n;j5++)
													{
														for(int i6=j5+1;i6<n;i6++)
														{
															for(int j6=i6+1;j6<n;j6++)
															{
																for(int i7=j6+1;i7<n;i7++)
																{
																	for(int j7=i7+1;j7<n;j7++)
																	{
																		for(int i8=j7+1;i8<n;i8++)
																		{
																			for(int j8=i8+1;j8<n;j8++)
																			{
																				for(int i9=j8+1;i9<n;i8++)
																				{
																					for(int j9=i9+1;j9<n;j9++)
																					{
																						if(m==20)
																						{
																							if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]&a[j6]&a[i7]&a[j7]&a[i8]&a[j8]&a[i9]&a[j9]))
																								mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]&a[j6]&a[i7]&a[j7]&a[i8]&a[j8]&a[i9]&a[j9];
																						}
																					}
																					if(m==19)
																					{
																						if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]&a[j6]&a[i7]&a[j7]&a[i8]&a[j8]&a[i9]))
																							mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]&a[j6]&a[i7]&a[j7]&a[i8]&a[j8]&a[i9];
																					}
																				}
																				if(m==18)
																				{
																					if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]&a[j6]&a[i7]&a[j7]&a[i8]&a[j8]))
																						mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]&a[j6]&a[i7]&a[j7]&a[i8]&a[j8];
																				}
																			}
																			if(m==17)
																			{
																				if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]&a[j6]&a[i7]&a[j7]&a[i8]))
																						mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]&a[j6]&a[i7]&a[j7]&a[i8];
																			}
																		}
																		if(m==16)
																		{
																			if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]&a[j6]&a[i7]&a[j7]))
																					mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]&a[j6]&a[i7]&a[j7];
																		}
																	}
																	if(m==15)
																	{
																		if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]&a[j6]&a[i7]))
																				mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]&a[j6]&a[i7];
																	}
																}
																if(m==14)
																{
																	if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]&a[j6]))
																			mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]&a[j6];
																}
															}
															if(m==13)
															{
																if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6]))
																		mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]&a[i6];
															}
														}
														if(m==12)
														{
															if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5]))
																	mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]&a[j5];
														}
													}
													if(m==11)
													{
														if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5]))
															mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]&a[i5];
													}
												}
												if(m==10)
												{
													if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4]))
														mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]&a[j4];
												}
											}
											if(m==9)
											{
												if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4]))
													mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]&a[i4];
											}
										}
										if(m==8)
										{
											if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3]))
												mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]&a[j3];
										}
									}
									if(m==7)
									{
										if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3]))
											mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]&a[i3];
									}
								}
								if(m==6)
								{
									if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2]))
										mx=a[i]&a[j]&a[i1]&a[j1]&a[i2]&a[j2];
								}
							}
							if(m==5)
							{
								if(mx<(a[i]&a[j]&a[i1]&a[j1]&a[i2]))
									mx=a[i]&a[j]&a[i1]&a[j1]&a[i2];
							}
						}
						if(m==4)
						{
							if(mx<(a[i]&a[j]&a[i1]&a[j1]))
								mx=a[i]&a[j]&a[i1]&a[j1];
						}
					}
					if(m==3)
					{
						if(mx<(a[i]&a[j]&a[i1]))
							mx=a[i]&a[j]&a[i1];
					}
				}
			}
		}
		cout << mx;
	}
	return 0;
}
